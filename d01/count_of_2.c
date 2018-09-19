//REMOVE THIS SHIT
#include <stdio.h>
//PLEASE

/*int		count_of_2(int n)
{
	int counter; //two's counter
	int arr[n];

	counter = 0;
	if (n <= 1)
		return (0);
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
		if (arr[i] > 1)
		{
			if (arr[i] % 10 == 2 || arr[i] / 10 == 2)
			{
				counter += 1;
				arr[i] /= 10;
			}
			if (arr[i] / 10 == 2)
			{
				counter += 1;
				arr[i] %= 10;
			}
			if (arr[i] % 10 == 2)
			{
				counter += 1;
				arr[i] /= 10;
			}
		}
	}
	return (counter);
}*/

// int		count_of_2(int n)
// {
// 	int counter = 0;
//     int temp =
//     //int temp;
//     //int temp[num]; // all numbers that has 2's from num
//
//     //int res = count_of_2(num);
//
//     if (n <= 1)
//     {
//         printf("num is smaller or equal to 1\n");
//         return (0);
//     }
//     while (arr[i] <= n)
//     {
//         arr[i] = i;
//         printf("Numbers given before finding a two: %d\n", arr[i]);
//         if (arr[i] >= 2)//|| arr[i] / 10 == 2)
//         {
//             if (arr[i] % 10 == 2)// || arr[i] / 10 == 2)
//                 counter++;
//             if (arr[i] / 10 == 2 && arr[i] != 0)
//             {
//                 counter++;
//                 arr[i++];
//             }
// 			else if (arr[i] / 10 == 1)
// 				arr[i] = arr[i] + (10 - 2);
// 			else
// 				arr[i] += 10;
//             // if (arr[i] % 10 == 2 || arr[i] / 10 == 2)
//             //     counter += 1;
// 			// arr[i] /= 10;
//         }
//         printf("2's found so far: %d\n", counter);
//     }
// 	return (counter);
// }

// int		count_of_2(int n)
// {
// 	int counter;
//
// 	counter = 0;
// 	while (n > 0)
// 	{
// 		if (n % 10 == 2)
// 			counter++;
// 		n /= 10;
// 	}
// 	return (counter);
// }
//
// int		count_of_2_range(int n)
// {
// 	int counter;
//
// 	counter = 0;
// 	for (int i = 2; i <= n; i++)
// 		counter += count_of_2(i);
// 	return (counter);
// }

int		main(void)
{
	//int num = 25;
	int res = count_of_2(300);

	printf("%d\n", res);
	return (0);
}

/*int		main(void)
{
	int counter = 0;
	int num = 25;
	int arr[num]; // all numbers [0...num]
	//int temp;
	//int temp[num]; // all numbers that has 2's from num

	//int res = count_of_2(num);

	if (num <= 1)
	{
		printf("num is smaller or equal to 1\n");
		return (0);
	}
	for (int i = 0; i <= num; i++)
	{
		arr[i] = i;
		printf("Numbers given before finding a two: %d\n", arr[i]);
		if (arr[i] > 1)//|| arr[i] / 10 == 2)
		{
			if (arr[i] % 10 == 2)// || arr[i] / 10 == 2)
			{
				counter += 1;
				arr[i] /= 10;
			}
			if (arr[i] / 10 == 2)
			{
				counter += 1;
				arr[i] %= 10;
			}
			if (arr[i] % 10 == 2 || arr[i] / 10 == 2)
				counter += 1;
		}
		printf("Counter: %d\n", counter);
	}
	//printf("There are %d of 2's\n", res);
}*/
