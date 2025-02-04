#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int	size = start - end;
	int	i = 0;
	int	*nbrs;

	if (end > start)
		size *= -1;
	size++;

	nbrs = (int *)malloc(sizeof(int) * size);
	if (nbrs)
	{
		while (i < size)
		{
			if (start > end)
				nbrs[i] = end + i;
			else
				nbrs[i] = end - i;
			i++;
		}
	}
	return(nbrs);
}

int main()
{
    int start = 9;
    int end = 3;
    int *array;
    int i = 0;
    int size = start - end;

	if (end > start)
		size *= -1;
	size++;

    array = ft_rrange(start, end);
    if (array)
    {
		while (i < size)
			printf("%d ", array[i++]);
		printf("\n");

		free(array);
		return 0;

    }

}