#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//哈希的散列长度是26
#define HASH_CYCLE 26	
//定义哈希表结构
typedef struct node {
	char  *word;
	struct node *next;
} node;

typedef struct unit {
	node *start;
	node *last;
	int   num;
} unit;

typedef struct hashtable {
	unit *set;
	int   cap;
} hashtable;

static inline void 		 hash_free(hashtable *ht);
static inline int 		 hashmap(const hashtable *ht, const char *word);
static inline void 		 hash_insert(hashtable *ht, const char *word);
static inline hashtable *hash_create(const int capacity);

int main(void) {
	//读入敏感词个数
	int  word_num = 0;
	char word_temp[50] = {0}, buf[50] = {0};
	
	scanf("%d", &word_num);
	//创建哈希表结构并且将敏感词存储进hash表
	hashtable *ht = NULL;
	ht = hash_create(HASH_CYCLE);

	for (int i = 0; i < word_num; i++) {
		scanf("%s", word_temp);
		hash_insert(ht, word_temp);
	}

	//读入句子查找是否是敏感词并进行输出
	while (getchar() != '\n' && getchar() != EOF);

	for (int j = 0, k = 0; j < 2000; j++) {
		buf[k] = getchar();

		if ((buf[k] >= 'a' && buf[k] <= 'z') || (buf[k] >= 'A' && buf[k] <= 'Z'))
			k++;
		else {
			char ch = buf[k];

			buf[k] = '\0';
			if (hashmap(ht, buf) == 1) {
				for (int i = 0; i < strlen(buf); i++)
					printf("*");
				printf("%c", ch);
			} else {
				printf("%s", buf);
				printf("%c", ch);
			}
			k = 0;

			if (ch == '\n')
				break;
		}
	}

	hash_free(ht);
	return 0;
}
//创建hash表函数
static inline hashtable *hash_create(const int capacity) {
	unit *set = NULL;
	set = calloc(1, sizeof(unit)*capacity);

	hashtable *ht = NULL;
	ht  = calloc(1, sizeof(hashtable));

	ht->set = set;
	ht->cap = capacity;
	
	return ht;
}
//插入敏感词操作
static inline void hash_insert(hashtable *ht, const char *word) {
	int len = strlen(word), index = word[0]-'a';
	node *temp = NULL;

	for (temp = ht->set[index].start
		; temp != NULL
		; temp = temp->next) {
		if (strcmp(word, temp->word) == 0)
			return;
	}

	node *newnode = malloc(sizeof(node));
	newnode->word = malloc(sizeof(char)*len);
	newnode->next = NULL;
	memcpy(newnode->word, word, len);

	if (ht->set[index].num == 0) {
		ht->set[index].start = newnode;
		ht->set[index].last  = newnode;
		ht->set[index].num++;
		return;
	}
	else {
		ht->set[index].last->next = newnode;
		ht->set[index].last 	  = newnode;
		ht->set[index].num++;
	}
}
//hash查询
static inline int hashmap(const hashtable *ht, const char *word) {
	char  buf[100] = {0};
	node *temp 	   = NULL;

	for (int i = 0; i < strlen(word); i++) {
		if (word[i] >= 'A' && word[i] <= 'Z')
			buf[i] = word[i]+32;
		else
			buf[i] = word[i];
	}

	int   index    = buf[0]-'a', ret = 0;
	for (temp = ht->set[index].start; temp != NULL; temp = temp->next) {
		if (strcmp(temp->word, buf) == 0) {
			ret = 1;
			break;
		}
	}

	return ret;
}
//hash表释放
static inline void hash_free(hashtable *ht) {
	node *temp = NULL, *temp1 = NULL;
	
	for (int i = 0; i < HASH_CYCLE; i++) {
		for (temp = ht->set[i].start; temp != NULL; temp = temp1) {
			temp1 = temp->next;
			free(temp->word);
			free(temp);
		}
	}
	free(ht->set);
	free(ht);
	ht = NULL;
}


