int solution(int number)
{
    if (number < 0)
        return 0;
    int threes = (number - 1) / 3;
    int fives = (number - 1) / 5;
    int both = (number - 1) / 15;
    int sum = 0;
    for (int i = 1; i <= threes; i++)
    {
        sum += (3 * i);
    }
    for (int i = 1; i <= fives; i++)
    {
        sum += (5 * i);
    }
    for (int i = 1; i <= both; i++)
    {
        sum -= (15 * i);
    }
    return sum;
}