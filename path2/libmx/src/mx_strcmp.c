 int mx_strcmp(const char *s1, const char *s2) {
	int i = 0;

	while(s1[i] && s2[i]) {
		if(s1[i] != s2[i]) {
			return s1[i] - s2[i];
		} 
		i++;
	}
	if(s1[i] != '\0' && s2[i] == '\0') {
		return s1[i];
	} else if (s2[i] != '\0' && s1[i] == '\0') {
		return -s2[i];
	}
	return 0;
}
