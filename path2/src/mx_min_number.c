int mx_min_number(int *dest, int kilkist, int *vis) {
	int min = 2147483647;

	for (int i = 0; i < kilkist; i++) {
		if (dest[i] != 0 && vis[i] != 1) {
			if (min > dest[i]) {
				min = dest[i];
			}
		}
	}
	return min;
}
