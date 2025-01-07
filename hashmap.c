#include<stdio.h>
#include<stdlib.h>

#define SIZE 9
#define MAX 100

struct Element{
    int key;
    char name[MAX];
    int age;
    //int id;
};//һ��Ԫ�صļ�:keyҲ���������һ������
//����ѧ��,���,���֤�ŵ�Ҳ����������ǰ�

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
    //ֻҪ��֤�����Եľ�һ��û�й�ϣ��ͻ
    //��Ϊ���Ժ�����˫��ĳ������
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
        printf("����û�и�Ԫ��!!!");
        return 0;
    }
    return hashTable->table[hashCode]->key==key;
}
//���ڲ���git�Ĺ���
//123

E* create(int key,char name[],int age){
    E* element=(E*)malloc(sizeof(E));
    element->key=key;
    element->name=name;
    element->age=age;
    return element;
}

