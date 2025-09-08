subroutine dscal(n, a, x, inc_x)
    use, intrinsic :: iso_c_binding, only: c_double, c_int

    implicit none

    integer, intent(in) :: n
    real(c_double), intent(in) :: a
    real(c_double), intent(inout) :: x(*)
    integer(c_int), intent(in) :: inc_x
    integer :: i_stop, i

    i_stop = n*inc_x
    do i = 1, i_stop, inc_x
        x(i) = a*x(i)
    end do
end subroutine dscal
