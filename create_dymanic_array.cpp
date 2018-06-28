int** num = new int*[T];
	for (int i = 0; i < T; i++)
		num[i] = new int[N];
    
    // while delete we have to delete as we create 
    1. delete all colums 
    2. delete all rows. 
