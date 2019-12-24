void mx_swap_char(char *s1, char *s2) {
	char buff;
	if(*s1 && *s2) {
		buff = *s1;
		*s1 = *s2;
		*s2 = buff;
	}
}
