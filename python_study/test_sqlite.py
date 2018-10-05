#!/usr/bin/python

# making a demo of some simple sqlite operations
  
import unittest
import sqlite3
import os

database_schema = ( "create table key_val ( name text, content text )" ,)

insert_stmt = "insert into %s values (?, ?)" 
update_stmt = "update %s set content = ? where name = ?"
query_stmt = "select name, content from %s where name = ?"

def createDB(conn, schema):
    c = conn.cursor()
    for statement in database_schema:
        c.execute(statement) 
        conn.commit()
        
def insertPair(conn, table, key, val ):
    statement =  insert_stmt %table
    c = conn.cursor()
    c.execute(statement, (key, val) )
    conn.commit()
    
def updatePair(conn, table, key, val):
    statement = update_stmt % table
    c = conn.cursor()
    c.execute(statement, (key, val, ))
    conn.commit()
    
def getPair(conn, table, key):
    query = query_stmt  % table
    c = conn.cursor()
    return c.execute(query, (key,)).fetchall()
    
    

class TEST(unittest.TestCase):
    
    def test1_create (self):
        database = 'key.db'
        os.remove(database)
        conn = sqlite3.connect(database)
        createDB(conn, database_schema )
        table = "key_val"
        key = 'a key'
        val = "a val"
        val2 = "another val"
        
        #insertPair(conn, table, key, val )
        insertPair(conn, table, key, val )
        pairs = getPair(conn, table , key)
        self.assertTrue(len(pairs) == 1)
        self.assertEqual( pairs[0], (key,val) )
        
        
        insertPair(conn, table, key, val2 )
        pairs = getPair(conn, table , key)
        self.assertTrue(len(pairs) == 2)
        self.assertEqual( pairs[0], (key,val) )
        self.assertEqual( pairs[1], (key,val2) )
        



if __name__ == "__main__":
    unittest.main()
