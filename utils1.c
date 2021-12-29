int	_check_value_atoi_(long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}