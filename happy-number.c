#define HASHSIZE	101

struct list {
	struct list *next;
	int key;
	int value;
} *hashtab[HASHSIZE];

unsigned hash(int key)
{
	unsigned index;

	index = key % HASHSIZE;

	return index;
}

struct list *lookup(int key, int value)
{
	struct list *np;
	int index;

	index = hash(key);
	for (np = hashtab[index]; np != NULL; np = np->next) {
		if (np->value == value)
			return np;
	}

	return NULL;
}

struct list *insert(int key, int value)
{
	struct list *np, *ptr;
	unsigned index = 0;

	np = (struct list *)malloc(sizeof(*np));
	if (np == NULL)
		return NULL;
	np->key = key;
	np->value = value;
	np->next = NULL;
	index = hash(key);

	if (hashtab[index] == NULL) {
		hashtab[index] = np;
	} else {
		ptr = hashtab[index];
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = np;
	}

	return np;
}

void display(int N)
{
	int i;
	struct list *np;

	for (i = 0; i < N; i++) {
		for (np = hashtab[i]; np != NULL; np = np->next) {
			printf("[%d,%d]->", np->key, np->value);
		}
		printf("\n");
	}
}

void clear(void)
{
	int i;

	for (i = 0; i < HASHSIZE; i++)
		hashtab[i] = NULL;
}


bool isHappy(int n) 
{
    struct list *np;
    
    if (n == 0) return false;
    if (n == 1) return true;
    clear();
    
    while (1) {
        int r, k = 0, s = 0;
        while (n != 0) {
            r = n % 10;
            k = k + r;
            s = s + r*r;
            n = n / 10;
        }
        if (s == 1)
            return true;
        np = lookup(k, s);
        if (np != NULL)
            return false;
        insert(k, s);
        n = s;
    }
    
    return 0;
}
