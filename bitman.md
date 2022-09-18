"https://www.youtube.com/watch?v=5rtVTYAk9KQ&list=PLN4aKSfpk8TQq8ySZsy266qAWBnR2sN0G&index=1&t=5440s"
"https://www.youtube.com/watch?v=klnI-RDIc6U&list=PLjeQ9Mb66hM0ewIZ50zJKoU8v8Wc-ODTt&index=2"

## swap 2 numbers using XOR
```
	{
		int a = 5,b = 7;
		a = a^b;        a = 5^7
		b = a^b;		b = 5^7^7 = 5
		a = a^b;		a = 5^7^5 = 7
	}
```

## get the index of first set bit from left / last set bit from right
```
	{
		let number be n
		index of first set bit is floor(log2(n)) -> 0-based indexing from right
		
		this can be extended to find total number of bits required to represent this number n in binary
		-> floor(log2(n)) + 1
	}
```

## get the index of last set bit from left / first set bit from right
	{
		If number is N
		N & ~(N-1) => on doing this we get a number where only the right most set bit is 1 and rem all bits become 0
		now finding it's position is easy by using log2
		
		log2(N & ~(N-1)) -> gives the index of first set bit from right
	}
	{
		int cnt = 0;
		while(N != 0){
			if(N & 1 == 1)
				break;
			cnt++;
			N = N>>1;
		}
	}
	
## clear the last set bit from left / first set bit from right 
	{
		If number is N 
		ans = N & (N-1)
		'ans' is the number we'll get after clearing the last set bit from left
		
		eg: N = 12 
		{
			12 = 1100;  11 = 1011
			ans = 1100 & 1011 = 1000
		}
	}

## check if a number is power of 2 or not 
	{
		if number is N
		if(N & N-1 == 0) then number is power of 2
		
		eg: N = 16 
		{
			16 = 10000; 15 = 01111
			10000 & 01111 = 00000;
		}
	}
	
## count number of set bits
```
	{
		int count = 0;
		while(num != 0){
			num = num & num-1;
			count++;
		}
		'here we are continuously clearing the last set bit from left untill number becomes 0'
		Time Complexity -> O(number of set bits)
	}
	{
		int count = 0;
		while(num != 0){
			if(num & 1 == 1) count++;
			num = num>>1;
		}
	}
```

## in a given array all numbers are repeated twice expect one number. Find the number which appears only once
```
	{
		int arr;
		int XOR = 0;
		for(i = 0 -> arr.length){
			XOR = XOR ^ arr[i];
		}
		return XOR;
	}
```
	
## find the XOR of all the numbers from 1-N
```
	{
		if(N % 4 == 0) XOR of all numbers from 1-N is N
		if(N % 4 == 1) XOR of all numbers from 1-N is 1
		if(N % 4 == 2) XOR of all numbers from 1-N is N+1
		if(N % 4 == 3) XOR of all numbers from 1-N is 0	
	}
```
	
## find the XOR of all the numbers from L-R
```
	{
		ans = (XOR of all the numbers from 1-R) ^ (XOR of all the numbers from 1-(L-1));
		
		eg:XOR of all the numbers from 3-7
		{
			required = 3^4^5^6^7
			here L = 3 and R = 7
			
			ans = (1^2^3^4^5^6^7) ^ (1^2)
		}
	}
```