; replacement.asm
; Точка входа main
; Linux x86-64, System V ABI

global main
extern malloc
extern create_array
extern resize
extern process_array

section .text

main:
    push rbp
    mov rbp, rsp

    ; malloc(5*4)
    mov edi, 20            ; size = 5 * sizeof(int)
    call malloc

    mov r12, rax           ; сохранить указатель массива

    mov rdi, r12           ; 1-й аргумент
    call create_array

    mov rdi, 5
    call resize

    ; arr[0] = 10; call process_array
    mov dword [r12 + 0], 10
    mov rdi, 0           ; 1-й аргумент
    xor eax, eax           ; очистка rax (для varargs ABI)
    call process_array

    ; arr[1] = 20; call process_array
    mov dword [r12 + 4], 20
    mov rdi, 1
    xor eax, eax
    call process_array

    ; arr[2] = 30; call process_array
    mov dword [r12 + 8], 30
    mov rdi, 2
    xor eax, eax
    call process_array

    ; return 0
    mov eax, 0
    leave
    ret

