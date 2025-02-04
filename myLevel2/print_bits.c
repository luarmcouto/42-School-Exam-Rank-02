#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	bit = 0;

	while (i > 0)
	{
		bit = (bit << 1) | (octet & 1);
		octet = octet >> 1;
		i--;
	}
	return (bit);
}


int	main()
{
	unsigned char nbr = 16;

	print_bits(nbr);
	nbr = reverse_bits(nbr);
	write(1, "\n", 1);
	print_bits(nbr);
}