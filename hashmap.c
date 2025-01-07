#include<stdio.h>
#include<stdlib.h>

#define SIZE 9
#define MAX 100

struct Element{
    int key;
    char name[MAX];
    int age;
    //int id;
};//一个元素的键:key也是它自身的一个属性
//正如学号,编号,身份证号等也属于这个人那般

typedef struct Element E;

typedef struct HashTable_{
    E* table;
};

typedef struct HashTable_ HashTable;

int main(){


    return 0;
}

int hash(int key){
    return (2*key+3)%SIZE;
    //只要保证是线性的就一定没有哈希冲突
    //因为线性函数是双射的充分条件
}

void init(HashTable* hashTable){
    hashTable->table=(E*)malloc(sizeof(E)*SIZE);
    for(int i=0;i<SIZE;i++){
        hashTable->table[i]=NULL;
    }
}

void insert(HashTable* hashTable,E* element){
    int hashCode=hash(element->key);
    hashTable->table[hashCode]=element;
}

int find(HashTable* hashTable,int key){
    int hashCode=hash(key);
    if(!hashTable->table[hashCode]){
        printf("表中没有该元素!!!");
        return 0;
    }
    return hashTable->table[hashCode]->key==key;
}
//用于测试git的功能
//123

E* create(int key,char name[],int age){
    E* element=(E*)malloc(sizeof(E));
    element->key=key;
    element->name=name;
    element->age=age;
    return element;
}

