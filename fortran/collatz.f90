program collatz
    implicit none
    integer :: a
    print *, "시작 숫자를 입력하세요."
    read *, a
    do while(a/=1)
        if (mod(a,2)==0) then
            a=a/2
        else
            a=a*3+1
        endif
        print *, a
    enddo
end program