int main(void)
{
	int i;
	int numbers[10] = {0,1,2,-3,4,-5,6,-7,8,9};
	i = 0;
	while (i < 10) {
		if (numbers[i] < 0) {
			numbers[i] += 42;
		}
		i++;
	}
	// numbers = {0, 1, 2, 39, 4, 37, 6, 35, 8, 9}
}
