#!/bin/bash

#DEBUG=1

APT=
user=
osVer=
osName=
cPath=$(dirname "${BASH_SOURCE[0]}")
tmpPath="/tmp/android-env"
resPath=
resUrl="https://cqdev.top:8989/android-env-res"

# home path
homePath="/home"

AUTO="1 3 4 7 9"

VERNO="1.4-20200606"

# PrintErr
function PrintErr() {
    printf "\033[31m$*\033[0m\n"
}

# PrintDbg
function PrintDbg() {
    [ "$DEBUG" == "1" ] && printf "\n\033[36m$*\033[0m\n"
}

# PrintInfo
function PrintInfo() {
    printf "\033[33m$*\033[0m\n"
}

# Println
function Println() {
    printf "$*\n"
}

# 安装每个包，避免某个包安装失败中断安装其他包
function InstallPkg() {
    if [ "$#" -le "0" ]; then
        PrintErr "E: no packages"
        return -1
    fi

    for pkg in $*; do
        $APT -y install $pkg
    done
}

function SetSources() {
    if [ -z "$(grep -l aliyun /etc/apt/sources.list 2>/dev/null)" ]; then
        cp -f /etc/apt/sources.list /etc/apt/sources.list.save
        sed -i '/^deb.*/s/\/\/.*com/\/\/mirrors.aliyun.com/g' /etc/apt/sources.list
    fi
}

function DownloadRes() {
    wget -nv -O $resPath"/ccache"        $resUrl"/ccache"
    wget -nv -O $resPath"/etc.tgz"       $resUrl"/etc.tgz"
    wget -nv -O $resPath"/home_vimrc"    $resUrl"/home_vimrc"
    wget -nv -O $resPath"/inputrc"       $resUrl"/inputrc"
    wget -nv -O $resPath"/make_381.tgz"  $resUrl"/make_381.tgz"
    wget -nv -O $resPath"/51-android.rules"  $resUrl"/51-android.rules"
}

# 初始化一些环境
function InitEnv() {
    PrintInfo "Initialize environment ...\n"

    user=$(who am i | awk '{print $1}')
    if [ -z "$user" ]; then
        user=$(who | awk 'NR==1{print $1}')

        if [ -z "$user" ]; then
            exit 1
        fi
    fi

    # unset LC_ALL
    # todo-20 sambashare gid = 1000 issue

    # todo-20 test-14-16-18
    homePath="$homePath/$user"

    # Detect Ubuntu Version
    osName=$(lsb_release -cs)
    if [ "$osName" = "trusty" ]; then
        PrintInfo "INFO: Ubuntu Version: 14.04"
        osVer=14
        APT=apt
    elif [ "$osName" = "xenial" ]; then
        PrintInfo "INFO: Ubuntu Version: 16.04"
        osVer=16
        APT=apt
    elif [ "$osName" = "bionic" ]; then
        PrintInfo "INFO: Ubuntu Version: 18.04"
        osVer=18
        APT=apt
    elif [ "$osName" = "focal" ]; then
        PrintInfo "INFO: Ubuntu Version: 20.04"
        osVer=20
        APT=apt
    else
        PrintErr "ERROR: Unknown linux distribution: $osName"
        exit -1
    fi

    PrintInfo "INFO: user is $user"
    PrintInfo "INFO: home is $homePath"
    PrintInfo "INFO: cPath is $cPath"

    # {
    for i in `seq -w 4 -1 0`; do
        echo -en "Please check up. wait \e[0;31m$i\e[0m second...\r"
        [ "$i" != "0" ] && sleep 1
    done
    echo -en "\n"
    # } &
    # {
    # read yes
    # } &
    # wait 3000

    # 检查 apt 占用
    $APT -y clean 2>/dev/null
    # if [ $? -ne 0 ]; then
        # PrintErr "error: apt 已经在运行."
        # exit -1
    # fi

    SetSources

    if [ -e "$cPath/res/ccache" ]; then
        resPath="$cPath/res"
    else
        if [ -e "$tmpPath" ]; then
            rm -rf $tmpPath
        fi
        mkdir $tmpPath
        resPath=$tmpPath
        DownloadRes
    fi

    if [ -z "$resPath" ]; then
        PrintErr "resPath is null"
    fi

    chmod -R a+x $resPath
}

function Install_78Share() {
    if [ -z "$(grep -l -m1 '//192.168.0.78/share' /etc/fstab 2>/dev/null)" ]; then
        $APT -y update
        InstallPkg cifs-utils
        mkdir /mnt/78server
        ln -sf /mnt/78server $homePath/78server
        chown -h $user:$user $homePath/78server

        echo "# mount 78server" >> /etc/fstab
        echo "//192.168.0.78/share /mnt/78server cifs username=Administrator,password=,uid=1000,gid=1000,nofail,_netdev 0 0" >> /etc/fstab
        mount -a
    else
        PrintInfo "已存在共享"
    fi
}

function Install_ipNat() {
    ## test-14-16-18
    filepath="/etc/network/if-up.d/cq-dnat"

    sudo printf ""
    [ "$?" -eq "0" ] || exit

    sudo touch $filepath
    sudo chmod 755 $filepath

sudo cat > $filepath <<EOF
#!/bin/sh

count=\$(iptables -n -t nat -L OUTPUT 2>/dev/null | grep "122.227.143.251" | wc -l)

if [ "\$count" -eq "0" ]; then
iptables -t nat -A OUTPUT -d 192.168.3.77 -j DNAT --to-destination 122.227.143.251
iptables -t nat -A OUTPUT -d 192.168.3.78 -j DNAT --to-destination 122.227.143.251
iptables -t nat -A OUTPUT -d 192.168.3.79 -j DNAT --to-destination 122.227.143.251
echo "ip redirection successful."
else
echo "The NAT configuration already exists."
fi

EOF

    sudo $filepath

}

function Install_un_ipNat() {
    filepath="/etc/network/if-up.d/cq-dnat"

    sudo printf ""
    [ "$?" -eq "0" ] || exit

    count=$(sudo iptables -n -t nat -L OUTPUT 2>/dev/null | grep "122.227.143.251" | wc -l)

    if [ "$count" -ne "0" ]; then
        sudo iptables -t nat -D OUTPUT -d 192.168.3.77 -j DNAT --to-destination 122.227.143.251
        sudo iptables -t nat -D OUTPUT -d 192.168.3.78 -j DNAT --to-destination 122.227.143.251
        sudo iptables -t nat -D OUTPUT -d 192.168.3.79 -j DNAT --to-destination 122.227.143.251
    fi

    if [ -e $filepath ]; then
        sudo rm $filepath
        echo "remove ip redirection."
    fi
}

function Install_bbr() {

    #todo kernel > 4.9

    sudo bash -c 'echo "net.core.default_qdisc=fq" >> /etc/sysctl.conf'
    sudo bash -c 'echo "net.ipv4.tcp_congestion_control=bbr" >> /etc/sysctl.conf'

    sudo sysctl -p
}

function Install_swap() {

    sudo bash -c 'echo "vm.swappiness=10" >> /etc/sysctl.conf'

    sudo sysctl -p
}

function Install_docker() {
    $APT -y update
    $APT -y remove docker docker-engine docker.io containerd runc

    InstallPkg apt-transport-https ca-certificates curl gnupg-agent software-properties-common

    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

    add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

    $APT -y update

    InstallPkg docker-ce

    usermod -aG docker $user
}

# Install Android Builds Tools
function Install_1() {
    PrintInfo "Install Android Builds Tools ..."

    $APT -y update
    $APT -y upgrade
    InstallPkg git-core gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev libgl1-mesa-dev libxml2-utils xsltproc unzip
    InstallPkg gcc g++ libc6-dev tofrodos python-markdown libssl-dev ssh
    InstallPkg exfat-utils vim htop iotop iftop libswitch-perl screen ccache pm-utils bc cmake
    InstallPkg hexedit geany sysstat pigz rar

    # TOOD gitk : Depends: git (< 1:2.7.4-.)
    InstallPkg qgit gitk

    InstallPkg samba

    # todo-20 not found
    InstallPkg gnome-commander

    # todo-20: if > 20.04
    InstallPkg python python-crypto net-tools libncurses5

    if [ "$osVer" -lt "16" ]; then
        InstallPkg mingw32 lib32readline-gplv2-dev
    fi

    # Install make 3.81 ,todo-20
    if [ "$osVer" -ge "16" ]; then
        PrintInfo "Install make 3.81 ..."
        tar -xf ${resPath}/make_381.tgz -C /
    fi
}

# Install oracle jdk6
function Install_2() {
    PrintInfo "Install JDK6 ..."
    chmod a+x ${resPath}/jdk-6u45-linux-x64.bin
    ${resPath}/jdk-6u45-linux-x64.bin > /dev/null
    mkdir -p /usr/lib/jvm
    mv -f ${resPath}/jdk1.6.0_45 /usr/lib/jvm/jdk1.6.0_45

    update-alternatives --install /usr/bin/jar     jar     /usr/lib/jvm/jdk1.6.0_45/bin/jar 1
    update-alternatives --install /usr/bin/java    java    /usr/lib/jvm/jdk1.6.0_45/bin/java 100
    update-alternatives --install /usr/bin/javac   javac   /usr/lib/jvm/jdk1.6.0_45/bin/javac 100
    update-alternatives --install /usr/bin/javadoc javadoc /usr/lib/jvm/jdk1.6.0_45/bin/javadoc 100
    update-alternatives --install /usr/bin/javah   javah   /usr/lib/jvm/jdk1.6.0_45/bin/javah 100
    update-alternatives --install /usr/bin/javap   javap   /usr/lib/jvm/jdk1.6.0_45/bin/javap 100
}

# Install openjdk7 & openjdk8
function Install_3() {
    PrintInfo "Install openjdk7 & openjdk8 ..."
    add-apt-repository -y ppa:openjdk-r/ppa
    $APT -y update

    # todo-20 openjdk7
    if [ $osVer -ge "20" ]; then
		:
        # $APT -y software-properties-common
        # apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 0xB1998361219BD9C9
        # apt-add-repository 'deb http://repos.azulsystems.com/ubuntu stable main'
        # $APT -y update
        # InstallPkg -y zulu-7
    else
        InstallPkg openjdk-7-jdk
    fi

    InstallPkg openjdk-8-jdk
}

# Install mingw32 & gcc-4.4 for 16.04+
function Install_4() {
    if [ "$osVer" -ge "16" ]; then
        PrintInfo "Install mingw32 ..."
        sh -c "echo \"deb http://mirrors.aliyun.com/ubuntu trusty main universe\" > /etc/apt/sources.list.d/trusty.list"
        $APT -y update
        InstallPkg mingw32 gcc-4.4 g++-4.4 gcc-4.4-multilib g++-4.4-multilib

        rm /etc/apt/sources.list.d/trusty.list
        $APT -y update

        GCCBIN=$(ls /usr/bin/gcc-[0-9]*)
        GPPBIN=$(ls /usr/bin/g++-[0-9]*)

        poriority=0
        for i in $GCCBIN ; do
            update-alternatives --install /usr/bin/gcc gcc $i $[poriority+=100]
        done
        for i in $GPPBIN ; do
            update-alternatives --install /usr/bin/g++ g++ $i $[poriority+=100]
        done
    else
        PrintErr "ERROR: Not Ubuntu16.04 ..."
    fi
}

# Update git
function Install_5() {
    PrintInfo "Update git ..."
    # test-14-16-18
    add-apt-repository -y ppa:git-core/ppa
    $APT -y update
    InstallPkg git
}

#Update svn
function Install_6() {
    PrintInfo "Update svn ..."
    #todo-20
    if [ ! -f /etc/apt/sources.list.d/wandisco_svn19.list ]; then
        sh -c "echo \"deb http://opensource.wandisco.com/ubuntu ${osName} svn19\" > /etc/apt/sources.list.d/wandisco_svn19.list"
        wget -q http://opensource.wandisco.com/wandisco-debian.gpg -O- | sudo apt-key add -
        $APT -y update
        InstallPkg subversion
    fi
}

# Install etc & Setting up git & Setting up bashrc
function Install_7() {
    if [ ! -f /usr/local/bin/repo ]; then
        PrintInfo "Install etc ..."
        tar -xf ${resPath}/etc.tgz -C /

        ## vimrc
        cat ${resPath}/home_vimrc > $homePath/.vimrc
        chown ${user}:${user} $homePath/.vimrc

        ## inputrc
        cat ${resPath}/inputrc > $homePath/.inputrc
        chown ${user}:${user} $homePath/.inputrc

        ## sysctl for android studio
        echo "fs.inotify.max_user_watches=524288" >> /etc/sysctl.conf
        echo "fs.inotify.max_user_instances=2048" >> /etc/sysctl.conf
        sysctl -p
    fi

    if [ ! -f /etc/gitconfig ]; then
        PrintInfo "Setting up git ..."
        git config --system alias.br "branch"
        git config --system alias.st "status -sb"
        git config --system alias.co "checkout"
        git config --system alias.ci "commit"
        git config --system alias.di "diff"
        git config --system alias.lg "log --pretty=format:'%Cgreen%cd%Creset %Cred%h%Creset %s% Cgreen@%cn%Creset' --abbrev-commit --date=short"
        git config --system alias.lgg "log --graph --pretty=format:'%Cred%h%Creset%C(yellow)%d%Creset %s%Cgreen[%cd @%cn]%Creset' --abbrev-commit --date=short"
        git config --system core.editor vim
        git config --system core.autocrlf input
        git config --system core.safecrlf true
        git config --system core.filemode false
        git config --system core.quotepath false
        git config --system core.pager "less -x1,5"
        git config --system color.ui auto
        git config --system merge.tool vimdiff
        git config --system push.default simple
        git config --system gc.auto 0
    fi

    if [ ! -n "$(grep -m1 "Modified by android-env begin" $homePath/.bashrc)" ]; then
        PrintInfo "Setting up bashrc ..."
        if [ ! -e $homePath/.bashrc_orig ]; then
            cp $homePath/.bashrc $homePath/.bashrc_orig
            chown ${user}:${user} $homePath/.bashrc_orig
        fi

        echo "" >> $homePath/.bashrc
        echo "# Modified by android-env begin" >> $homePath/.bashrc

        echo "PS1='"'${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\[\033[01;33m\]$(__git_ps1 " (%s)")\n\[\033[01;31m\]\$ \[\033[00m\]'"'" >> $homePath/.bashrc

        echo "export PATH=\$PATH:." >> $homePath/.bashrc

        #echo "export LANGUAGE=C.UTF-8" >> $homePath/.bashrc
        #echo "export LANG=C.UTF-8" >> $homePath/.bashrc
        echo "export LC_ALL=C.UTF-8" >> $homePath/.bashrc
        #echo "export LC_TIME=C.UTF-8" >> $homePath/.bashrc

        echo "export USE_CCACHE=true" >> $homePath/.bashrc
        echo "export CCACHE_SLOPPINESS=time_macros,include_file_mtime,file_macro" >> $homePath/.bashrc
        echo "export CCACHE_UMASK=002" >> $homePath/.bashrc

        echo "# for android q" >> $homePath/.bashrc
        echo "export CCACHE_EXEC=/usr/bin/ccache" >> $homePath/.bashrc

        #echo "cd /home/$user/android 2>/dev/null" >> $homePath/.bashrc

        # bash history
        sed -i 's/^HISTSIZE=.*/HISTSIZE=6000/' $homePath/.bashrc
        sed -i 's/^HISTFILESIZE=.*/HISTFILESIZE=20000/' $homePath/.bashrc
        echo 'HISTTIMEFORMAT="%F %T "' >> $homePath/.bashrc

        echo "# Modified by android-env end" >> $homePath/.bashrc
        echo "" >> $homePath/.bashrc

        #PS1_TEXT="PS1=\'\${debian_chroot:+(\$debian_chroot)}\\\\[\\\\033[01;32m\\\\]\\\\u@\\\\h\\\\[\\\\033[00m\\\\][\\\\[\\\\033[01;34m\\\\]\\\\w\\\\[\\\\033[00m\\\\]]\\\\[\\\\033[01;33m\\\\]\$(__git_ps1 \" \(%s\)\")\\\\n\\\\[\\\\033[01;31m\\\\]\\\\\$ \\\\[\\\\033[00m\\\\]\'"
        COLOR_TEXT="force_color_prompt=yes"
        ALIAS_LL_TEXT="alias ll=\'ls -agFh --time-style=iso --group-directories-first\'"

        sed -i s/^.*force_color_prompt=yes.*/"${COLOR_TEXT}"/g $homePath/.bashrc
        #sed -i s/PS1=.*033.*/"${PS1_TEXT}"/g $homePath/.bashrc
        sed -i s/^.*alias[[:space:]]ll=.*/"${ALIAS_LL_TEXT}"/g $homePath/.bashrc
    fi

    # todo-20 fix git ssh issue on o1mp1 p0mp1
    if [ "$osVer" -ge "16" -a ! "$(grep -m1 android-env /etc/ssh/ssh_config 2>/dev/null)" ]; then
        sudo bash -c 'echo "# add by android-env" >> /etc/ssh/ssh_config'
        sudo bash -c 'echo "KexAlgorithms +diffie-hellman-group1-sha1" >> /etc/ssh/ssh_config'
    fi

    if [ ! -e "/etc/udev/rules.d/51-android.rules" ]; then
        PrintInfo "Setting up udev ..."
        cp $resPath/51-android.rules /etc/udev/rules.d/51-android.rules 2>>log
    fi

    PrintInfo "Setting up ccache ..."
    # setup ccache # test-14-16-18
    sudo -u $user ccache -M 100G

    ## 设置旧版本ccache，兼容 < Q
    sudo -u $user ${resPath}/ccache -M 100G

    chown -R ${user}:${user} $homePath/.ccache
}

# 其他配置(交互)
function Install_8() {
    PrintInfo "其他非必要配置 ..."
    ## TODO: tig
    # printf "\033[33m是否安装 tig ? (y/n): \033[0m"
    # read yes

    # if [ "$yes" == "y" ]; then
        # echo ">> 未实现"
    # else
        # echo ">> skip"
    # fi

    printf "\033[33m是否配置挂载共享 ? (y/n): \033[0m"
    read yes

    if [ "$yes" == "y" ]; then
        Install_78Share
    else
        echo ">> skip"
    fi

    printf "\033[33m是否配置重庆办IP重定向 ? (y/n): \033[0m"
    read yes
    if [ "$yes" == "y" ]; then
        Install_ipNat
    else
        echo ">> skip"
    fi

    if [ "$yes" == "n" ]; then
        printf "\033[33m是否移除重庆办IP重定向配置 ? (y/n): \033[0m"
        read yes
        if [ "$yes" == "y" ]; then
            Install_un_ipNat
        else
            echo ">> skip"
        fi
    fi

    printf "\033[33m是否配置 Google BBR ? (y/n): \033[0m"
    read yes
    if [ "$yes" == "y" ]; then
        Install_bbr
    else
        echo ">> skip"
    fi

    printf "\033[33m是否配置 swapness 为 10 ? (y/n): \033[0m"
    read yes
    if [ "$yes" == "y" ]; then
        Install_swap
    else
        echo ">> skip"
    fi

}

# Install Oracle VM VirtualBox
function Install_9() {
    PrintInfo "Install Oracle VM VirtualBox ..."
    # official source
    #$APT -y update
    #InstallPkg virtualbox virtualbox-guest-additions-iso # virtualbox-ext-pack build-essential linux-headers-$(uname -r)
    #InstallPkg build-essential virtualbox-guest-dkms virtualbox-guest-x11

    # TODO: 使用清华源会有公钥错误 https://mirrors.tuna.tsinghua.edu.cn/virtualbox/apt/
    if [ "$osVer" -lt "20" ]; then
        sh -c "echo \"deb https://download.virtualbox.org/virtualbox/debian ${osName} contrib\" > /etc/apt/sources.list.d/virtualbox.list"
    else
        sh -c "echo \"deb [arch=amd64] https://download.virtualbox.org/virtualbox/debian ${osName} contrib\" > /etc/apt/sources.list.d/virtualbox.list"
    fi

    if [ "$osVer" -ge "16" ]; then
        wget -q https://www.virtualbox.org/download/oracle_vbox_2016.asc -O- | sudo apt-key add -
    else
        wget -q https://www.virtualbox.org/download/oracle_vbox.asc -O- | sudo apt-key add -
    fi

    $APT -y update
    InstallPkg dkms
    InstallPkg virtualbox-6.1
   
    # TODO: vbox extpack
    # vboxmanage --version
    # https://download.virtualbox.org/virtualbox/6.1.8/Oracle_VM_VirtualBox_Extension_Pack-6.1.8.vbox-extpack

    usermod -a -G vboxusers $user
    usermod -a -G vboxsf $user
}

# Install Oracle VM VirtualBox (offline)
function Install_10() {
    PrintInfo "Install Oracle VM VirtualBox (offline) "

    VBver=
    VBdeb=$(ls ${resPath}/virtualbox-5.*?Ubuntu?${osName}_amd64.deb)
    VBext=$(ls ${resPath}/Oracle_VM_VirtualBox_Extension_Pack-5.*.vbox-extpack)

    $APT -y update
    InstallPkg dkms libsdl-ttf2.0-0 libsdl1.2debian
    dpkg -i $VBdeb

    usermod -a -G vboxusers $user

    VBoxManage extpack cleanup
    VBoxManage extpack install --replace $VBext
}

function Install_test() {
    PrintInfo "Install TEST "
}

# HELP
function PrintHelp() {
    Println "Usage: sudo ./android-env.sh <step...>"
    Println "Step:"
    Println "  0    -- 自动安装($AUTO)"
    Println "  1    -- 安装编译工具"
    Println "  2    -- 安装ORACLE JDK6"
    Println "  3    -- 安装OPEN JDK7 & JDK8"
    Println "  4    -- 安装mingw32 & gcc-4.4 (for >ubuntu 16.04)"
    Println "  5    -- 安装最新版本git"
    Println "  6    -- 安装最新版本svn"
    Println "  7    -- 配置bash & git & ccache"
    Println "  8    -- 其他配置(交互)"
    Println "  9    -- 在线安装VirtualBox"
    Println "  10   -- 离线安装VirtualBox(弃用)"
    Println "Example:"
    Println "  sudo ./android-env.sh 1 3 4 7 9"

}

# >>> MAIN <<<

if [ "$UID" -ne "0" ]; then
    PrintErr "ERROR: Permission denied! Please try running this command again as sudo."
    PrintHelp
    exit -1
fi

STEP=$*

PrintInfo ">>> Install Android Build Environment\n    ver: $VERNO"

if [ -z "$STEP" ]; then
    PrintErr "ERROR: 参数为空"
    PrintHelp
    exit -1
fi

# check 0
for i in $STEP ; do
    if [ "$i" = "e" ]; then
        exit 0
    elif [ "$i" = "0" ]; then
        PrintInfo "执行自动安装..."
        STEP=$AUTO
    fi
done

# 初始化环境
InitEnv

# 执行选定流程
for i in $STEP ; do
    PrintDbg ">> Install_$i"
    Install_$i
done

exit 0
