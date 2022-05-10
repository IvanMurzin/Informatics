#ifndef TABLE_H
#define TABLE_H

#include "KeySpace1.h"
#include "KeySpace2.h"
#include "CompositeKey.h"

typedef struct Table {
    int size;
    int maxSize;
    KeySpace1 *keySpace1;
    KeySpace2 *keySpace2;
} Table;

int getTable(Table** table, int maxSize);

/*
 * включение нового элемента в таблицу с соблюдением
 * ограничений на уникальность ключей всоответствующих
 * ключевых пространствах и уникальность составного ключа
 */
int put(Table *table, CompositeKey key, const char *data); // todo implement

/*
 * поиск в таблице элемента, заданного составным ключом
 */
Item* find(Table *table, CompositeKey key); // todo implement

/*
 * поиск в таблице элемента по любому заданному ключу;
 * результатом поиска должна быть копии
 * всех найденных элементов со значениями ключей
 */
int findByKey1(Table *table, Key key); // todo implement

int findByKey2(Table *table, Key key); // todo implement

/*
 * удаление из таблицы элемента, заданного составным ключом
 */
int delete(Table *table, CompositeKey key); // todo implement

/*
 * удаление из таблицы всех элементов,
 * заданного ключом в одном из ключевых пространств
 */
int deleteByKey1(Table *table, Key key1); // todo implement

int deleteByKey2(Table *table, Key key2); // todo implement

/*
 * вывод содержимого таблицы на экран,
 * при этом формат вывода долженсоответствовать элемента таблицы
 */

#endif
