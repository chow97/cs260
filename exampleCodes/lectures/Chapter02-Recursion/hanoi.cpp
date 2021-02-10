// Psuedocode

void solveTowers(count, source, dest, spare)
{
    if (count == 1)
    {
	// move disk from source to dest
    }
    else
    {
	solveTowers(count-1,source,spare,dest);
	solveTowers(1,source,dest,spare);
	solveTowers(count-1,spare,dest,source);
    }
}
