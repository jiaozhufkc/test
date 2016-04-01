#include <stdio.h>
#include <stdassert.h>

int searchPos(int * matrix, int len, int target)
{
    int i;
    int l_pos, r_pos, m_pos;
    int l_val, r_val, m_val;
    l_pos = 0;
    r_pos = len;
    
    for(i = 0; i < len;i++)
    {
        l_val = matrix[l_pos];
        r_val = matrix[r_pos];
        m_pos = (l_pos + r_pos) / 2;
        m_val = matrix[m_pos];
        
        if(target == l_val)
        {
            return l_pos;
        }
        else if(target == r_val)
        {
            return r_pos;
        }
        
        if(1 == (r_pos - l_pos))
        {
            return l_pos;
        }
        
        if(target > m_val){
            l_pos = m_pos;
        }
        else{
            r_pos = m_pos;
        }
    }
    printf("i %d\n", i);
}




bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int raw, col;
    int i, j;
    int *array;
    printf("i %d\n", target);
    col = searchPos(matrix[0], matrixColSize, target);
    
    if(matrix[0][col] ==  target)
    {
        return true;
    }
    
    array = malloc(matrixRowSize);
    if(NULL == array){
        assert(0);
    }
    for(i = 0; i < matrixRowSize; i++)
    {
        array[i] =  matrix[i][col];
    }
        
    raw = searchPos(array, matrixRowSize, target);
    
    if(matrix[raw][col] ==  target)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
/*
void main(void)
{
    int ret = 0;
    ret = searchMatrix(matrix, 5, 5, 5);
    printf("ret is %d\n", ret);
}*/
