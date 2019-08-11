//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	short n;

	scanf("%hi",&n);

	short arr[ n*n + 1 ];

	for (int i = 0 ; i < n; ++i)
	{
		for ( int j = 0; j < n; ++j)
		{
			scanf("%hi",&arr[ i*n + j]);
		}
	}

	short min = 1001;

	short new_city[n + 1]{};

	short visited = 0;

	short* ptr = arr;

	new_city[visited] = 0;

	while ( visited < n )
	{
		for (int i = 0; i < n; ++i)
		{
			arr[ i*n + new_city[visited] ] = 0;
		}

		visited++;

		min = 1001;
		for (int i = 0; i < n ; ++i)
		{
			if ( *(ptr + i) < min && *(ptr + i) > 0)
			{
				min = *(ptr+i);
				new_city[visited] = i;
			}
		}

		ptr = arr;

		ptr += n*new_city[visited];
	}

	for (int i = 1; i < n; ++i)
	{
		printf("%d ",new_city[i] + 1);
	}printf("\n");
}