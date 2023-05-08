#include <stdio.h>
#include <conio.h>
#include <memory.h>
#include <malloc.h>
#include <time.h>
 
 
class Stack
{
public:
    Stack(void);
    Stack(int size);
    virtual ~Stack(void);
    int Push(int number);
    int Pop(int& number);
    int SetSize(const int size);
    void Clear();
    int GetNumberElement() const;
 
private:
    Stack& operator=(const Stack& stack);
    Stack(const Stack& stack);
 
    int     m_index;
    int     m_size;
    int*    m_data;
};
 
 
Stack::Stack(void)
{
    m_size = 0;
    m_data = 0;
    m_index = -1;
}
 
Stack::Stack(int size)
{
    if(size > 0)
    {
        m_size = size;
        m_data = (int *)malloc(size * sizeof(int));
        memset(m_data, 0, size * sizeof(int));
    }
    else
    {
        m_size = 0;
        m_data = 0;
    }
    m_index = -1;
}
Stack::~Stack(void)
{
    Clear();
}
 
int Stack::SetSize(const int size)
{
    if(size > 0)
    {
        if(m_data)
        {
            free(m_data);
        }  
        m_index = -1;
        m_size = size;
        m_data = (int *)malloc(size * sizeof(int));
        memset(m_data, 0, size * sizeof(int));
    }
    return 0;
}
 
int Stack::Push(int number)
{
    if(m_index < m_size)
    {
        m_data[++m_index] = number;
        return 1;
    }
    return 0;
}
int Stack::Pop(int& number)
{
    if(m_index >= 0)
    {
        number = m_data[m_index--];
        return true;
    }  
    return false;
}
 
void Stack::Clear()
{
    if(m_data)
        free(m_data);
     m_data = 0;
    m_size = 0;
    m_index = -1;
}
 
int Stack::GetNumberElement() const
{
    return m_index + 1;
}
 
int main(int argc, char* argv[])
{      
    int number;
    printf("n = ");
    scanf("%d", &number);
        int k = number;
    Stack my_stack(200);
    while(number)
    {
        my_stack.Push(number % 2);
        number /= 2;
    }
    printf("\nConvert to binary:\n");
    printf("%d(10) = ", k);
    while(my_stack.GetNumberElement())
    {
        int number;
        my_stack.Pop(number);
        printf("%d", number);
    }
    printf("(2)\n");
    printf("\nDone!!!!!\n");
    getch();
    return 0;
}
