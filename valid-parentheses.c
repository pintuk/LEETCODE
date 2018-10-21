#define MAX     10000000

int stack[MAX];
int top = -1;

void push(int item)
{
        if (top > MAX) return;
        top++;
        stack[top] = item;
}

int pop()
{
        int item;

        item = stack[top];
        top--;

        return item;
}

int isempty()
{
        if (top < 0)
                return 1;
        return 0;
}

int check_stack(char ch)
{
        if (stack[top] == ch) {
                pop();
                return 1;
        }
        return 0;
}

int bracket_match(const char *expr)
{
        char ch;
        int i = 0, match = 1;

        while(expr[i] != '\0') {
                ch = expr[i++];

                if (ch == '(' || ch == '{' || ch == '[') {
                        push(ch);
                        continue;
                }
            
                if (isempty())
                    return 0;

                switch (ch) {
                        case ')':
                                match = check_stack('(');
                                if (match == 0) return 0;
                        break;

                        case '}':
                                match = check_stack('{');
                                if (match == 0) return 0;
                        break;

                        case ']':
                                match = check_stack('[');
                                if (match == 0) return 0;
                        break;
                }
                //i++;
        }
        //printf("stack top value = %d\n", top);

        if (match == 0 || !isempty()) return 0;

        return 1;
}

bool isValid(char* s) {
    top = -1;
    memset(stack, 0, sizeof(stack));
    if (s == NULL)
        return true;
    if (bracket_match(s) == 0)
        return false;
    return true;
}
