//TODO 
	shorten missing components() - map_components_check.c

1) check nr args is == 2; if not -> print usage and exit(1);
2) check file 
		if it ends with .ber;
		if it opens (permissions);

3) parse file
		find total bytes in file;
				read total bytes in string_map;

4) check map components
   check invalid symbols in map(string_map);

   convert string_map to 2d map and free(string_map);
		check structure;
		check borders;
		check for valid path;


movement[4]
i = -1;

movement[0] = right
movement[1] = down
movement[2] = left
movement[3] = up

while (p.coords != E.coords)	
	moved flag == 0;
	try 0
		while (movement[++i])
			if (p -> movement[i] == valid)
				add coord to list (history list -> visited coords);
				p -> location is = movement[i];
				moved flag == 1;
		
		if (moved flag == 0)
			step back
				go to previous coords
				delete the coord from history list
		 


FLOW :


