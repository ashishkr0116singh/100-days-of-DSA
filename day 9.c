int main() {
    char arr[256];
    scanf("%s", arr);
    int len = strlen(arr);
    int i = 0;
    int j = len - 1;
    while (i <= j) {
        char c = arr[i];
        arr[i] = arr[j];
        arr[j] = c;
        i++; j--;
    }
    printf("%s\n", arr);

}