#include <stdio.h>
#include <stdlib.h>

int	ft_rrange(int start, int end)
{
	int	*range;
	int	i = 0;
	int size = start - end;

	if (end > start)
		size *= -1;
	size++;
	range = (int *)malloc(sizeof(int *) * size);
	if (range)
	{
		range[0] = end;
		i++;
		while (size--)
		{
			if (start > end)
				range[i] = start - (size - 1);
			else
				range[i] = end - i;
			i++;
		}
	}
}