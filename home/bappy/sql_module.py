from datetime import *
import json
from flask import Flask, request, session
from collections import OrderedDict
import numpy as np
import pymysql

host = '127.0.0.1'
id='bappy'
pw='bappy'
db_name='bappy'

def comment_last_idx():
    host = '127.0.0.1'
    id='bappy'
    pw='bappy'
    db_name='bappy'
    conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
    curs=conn.cursor(pymysql.cursors.DictCursor)
    sql = """select co_idx from bd_comment order by co_idx desc limit 1"""
    curs.execute(sql)

    rows = curs.fetchall()
    #print(rows[0]['co_idx'])
    conn.close()
    return rows[0]['co_idx']

def board_last_idx():
    host = '127.0.0.1'
    id='bappy'
    pw='bappy'
    db_name='bappy'
    conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
    curs=conn.cursor(pymysql.cursors.DictCursor)
    sql = """select b_idx from bd_board order by b_idx desc limit 1"""
    curs.execute(sql)

    rows = curs.fetchall()
    #print(rows[0]['b_idx']+1)
    conn.close()
    return rows[0]['b_idx']


def member_last_idx():
    host = '127.0.0.1'
    id='bappy'
    pw='bappy'
    db_name='bappy'
    conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
    curs=conn.cursor(pymysql.cursors.DictCursor)
    sql = """select m_idx from bd_member order by m_idx desc limit 1"""
    curs.execute(sql)

    rows = curs.fetchall()
    #print(rows[0]['b_idx']+1)
    conn.close()
    return rows[0]['m_idx']


comment_last_idx()
board_last_idx()
