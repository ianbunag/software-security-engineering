int main(void)
{
    int num1 = 1;
    int num2 = 0x7fffffff;
    long long addition_result = num1 + num2;
    long long addition_result2 = num1 + (long long)num2;
    long long addition_result3 = num1 + num2 + (long long)num2;
    long long addition_result4 = (long long)num1 + num2 + num2;
    long long addition_result5 = num1 + (long long)num2 + num2;
    printf("%lld\n", addition_result);
    printf("%lld\n", addition_result2);
    printf("%lld\n", addition_result3);
    printf("%lld\n", addition_result4);
    printf("%lld\n", addition_result5);

    unsigned int num3 = 1;
    unsigned int num4 = 0xffffffff;
    unsigned long long uaddition_result = num3 + num4;
    unsigned long long uaddition_result2 = num3 + (unsigned long long)num4;
    unsigned long long uaddition_result3 = num4 + num4;
    unsigned long long uaddition_result4 = num4 + (unsigned long long)num4;
    unsigned long long uaddition_result5 = num4 + num3 + (unsigned long long)num4;
    printf("%llu\n", uaddition_result);
    printf("%llu\n", uaddition_result2);
    printf("%llu\n", uaddition_result3);
    printf("%llu\n", uaddition_result4);
    printf("%llu\n", uaddition_result5);
    return 0;
}
