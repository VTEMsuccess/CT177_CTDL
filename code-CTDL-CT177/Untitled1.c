void printInorder(Tree T)
{
    if (T == NULL)
        return;
    printInorder(T->Left,height);			
    printf("(%d - %d); ", T->Data,height);		
    printInorder(T->Right,height);
}
