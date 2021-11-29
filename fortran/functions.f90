!print 는 write랑 같고 (16) 은 *16 이랑 같고 출력이랑 입력 뒤에 붙은 *, 는 (*,*)
program functions
    implicit none
    integer (16) :: i, n, Luigi, s
    read *, n
    do i=2,n
        s=Luigi(n)
    enddo
    print *, "success!"
end program

integer(16) function Luigi(s)
implicit none
integer(16) :: s
do while(s.ne.1)
    if(mod(s,2).eq.0)then
        s=s/2
    else
        s=s*3+1
    endif
enddo
Luigi = s
return
end