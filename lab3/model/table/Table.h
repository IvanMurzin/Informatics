#ifndef TABLE_H
#define TABLE_H

#include "KeySpace1.h"
#include "KeySpace2.h"

typedef struct Table {
    int size;
    int maxSize;
    KeySpace1 *keySpace1;
    KeySpace2 *keySpace2;
} Table;

int getTable(Table **table, int maxSize);

/*
 * включение нового элемента в таблицу с соблюдением
 * ограничений на уникальность ключей всоответствующих
 * ключевых пространствах и уникальность составного ключа
 */
int put(Table *table, Item *item);

/*
 * поиск в таблице элемента, заданного составным ключом
 */
int find(Table *table, CompositeKey key, Item **result);

/*
 * поиск в таблице элемента по любому заданному ключу;
 * результатом поиска должна быть копии
 * всех найденных элементов со значениями ключей
 */
int findByKey1(Table *table, Key key, Item **result);

int findByKey2(Table *table, Key key, Item **result);

/*
 * удаление из таблицы элемента, заданного составным ключом
 */
int deleteAll(Table *table, CompositeKey key);

/*
 * удаление из таблицы всех элементов,
 * заданного ключом в одном из ключевых пространств
 */
int deleteByKey1(Table *table, Key key1);

int deleteByKey2(Table *table, Key key2);

int deleteByRangeKey1(Table *table, Key floor, Key selling);

void destroyTable(Table *table);

#endif
