void copyString(char *str1, char *str2, int index)
{
    if (str1[index] == '\0') {
        str2[index] = '\0';  // add null character to the end of str2
        return;
    } else {
        str2[index] = str1[index]; // copy the character from str1 to str2
        copyString(str1, str2, index+1); // move on to the next character
    }
}
 
int main()
{
    char str1[100], str2[100];
    printf("Enter a string: ");
    scanf("%s", str1);
    copyString(str1, str2, 0);
    printf("The copied string is: %s\n", str2);
    return 0;
}