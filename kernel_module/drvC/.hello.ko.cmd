cmd_/root/桌面/kerneltwo/hello.ko := ld -r -m elf_x86_64 -z max-page-size=0x200000 -T ./scripts/module-common.lds --build-id  -o /root/桌面/kerneltwo/hello.ko /root/桌面/kerneltwo/hello.o /root/桌面/kerneltwo/hello.mod.o ;  true
