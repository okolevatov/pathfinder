unsigned long mx_hex_to_nbr(const char *hex) {
	unsigned long result = 0;
	int i = 0;
	unsigned long b = 1;
	if(!hex) {
		return 0;
	}
	while(hex[i]) {
		i++;
	}
	for(int j = i - 1; j >= 0; j--) {
		if(hex[j] >= 48 && hex[j] <= 57) {
			result = result + (hex[j] - 48) * b;
			b = b * 16;
		} else if(hex[j] >= 65 && hex[j] <= 70) {
			result = result + (hex[j] - 55) * b;
			b = b * 16;
		} else if(hex[j] >= 97 && hex[j] <= 102) {
			result = result + (hex[j] - 87) * b;
			b = b * 16;
		} else {
			return 0;
		}
	}
return result;
}
