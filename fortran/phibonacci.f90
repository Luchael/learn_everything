program phibonacci
    implicit none
    integer(4) :: a
    integer(16) :: first, second, tmp
    print *, "몇번째 항을 구할지 입력하세요."
    read *, a
    first = 0;second=1;tmp=0
    do a=a-1,1,-1
        tmp = second
        second = second+first
        first = tmp
    enddo
    print *, second
end program