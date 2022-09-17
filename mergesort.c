# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include <time.h>


const int N = 1e7+7;

void mergesort(int a[],int l, int r);
void print_array(int a[], int n);

int main()
{
    int *a = (int *) calloc(N, sizeof N);
    assert(a && "Out of Memory!");
    srand(time(NULL));
    for(int i=0;i < N; i++)
	a[i] = rand() % N;

#ifdef _DEBUG
    print_array(a, N);
#endif
    clock_t c = clock();
    mergesort(a, 0, N-1);
    printf("Took %.6f sec...\n", (float)(clock() - c)/CLOCKS_PER_SEC);
#ifdef _DEBUG
    print_array(a, N);
#endif
    free(a);
    return 0;
}

void mergesort(int a[], int l, int r)
{
    if(l>=r)
	return;
    int m = (r-l)/2 + l;
    mergesort(a, l, m);
    mergesort(a, m+1, r);

    int li = m-l+1;
    int ri = r-m;

    int *ll = (int *) calloc(li, sizeof li);
    int *rr = (int *) calloc(ri, sizeof ri);

    assert(ll && rr && "Out of Memory!");

    for(int i=0;i < li; i++) ll[i] = a[i+l];
    for(int i=0;i < ri; i++) rr[i] = a[i+m+1];

    int i,j;
    i=j=0;
    int k=l;

    while(i<li && j<ri)
    {
	if(ll[i] < rr[j])
	    a[k++] = ll[i++];
	else
	    a[k++] = rr[j++];
    }

    while(i<li) a[k++] = ll[i++];
    while(j<ri) a[k++] = rr[j++];

    free(ll);
    free(rr);
}

void print_array(int a[], int n)
{
    for(int i=0;i < n;i++)
    {
	printf("%d ", a[i]);
	if((i+1) % 10 == 0)
	    printf("\n");
    }
    printf("\n");
}
