import json
from flask import Flask, request, session
from collections import OrderedDict
import numpy as np
import pymysql
from datetime import *
from sql_module import *

from datetime import datetime

strtype = '2018-09-15 00:01:14'
print(type(strtype))

logdate = datetime.strptime(strtype, '%Y-%m-%d %H:%M:%S')

app = Flask(__name__)
app.secret_key='abcde'

# DB 초기설정
host = '127.0.0.1'
id='bappy'
pw='bappy'
db_name='bappy'


def db_connect():
    conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
    curs=conn.cursor(pymysql.cursors.DictCursor)

def db_close():
    conn.close()

@app.route('/register', methods = ['GET', 'POST'])
def register():
    if request.method == 'POST':
        department = request.args.get('department')
        name = request.args.get('name')
        birth = request.args.get('birth')
        phone = request.args.get('phone')
        user_id = request.args.get('id')
        password = request.args.get('pass')
        nickname = request.args.get('nickname')
        index = member_last_idx()+1
        conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
        curs=conn.cursor(pymysql.cursors.DictCursor)


        sql = """insert into bd_member(m_department,m_name,m_birth,
                m_phone,m_id,m_pass,m_nickname,m_idx)
                values(
                '%s', '%s', '%s', '%s', '%s', '%s','%s', '%d'
                )
        """%(department,name,birth,phone,user_id,password,nickname,int(index))
        curs.execute(sql)
        conn.commit()
        conn.close()
        return "true"



@app.route('/')
def index():
    if "id" in session:
        data = []
        js = OrderedDict()
        js["id"]=session['id']
        js["name"]=session['name']
        js["gender"]=session['gender']
        js["mail"]=session['mail']
        js["department"]=session['department']
        js["nickname"]=session['nickname']
        js["birth"]=session['birth']
        js['job']=session['job']
        js['phone']=session['phone']
        js['profile']=session['profile']

        data.append(js)
        obj = json.dumps(data, ensure_ascii = False)
        return obj
    else:
        return "NO"

#------------------------------
@app.route('/login',methods = ['GET','POST'])
def login():
    if request.method == 'POST':
        conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
        curs=conn.cursor(pymysql.cursors.DictCursor)

        sql = """SELECT * FROM bd_member WHERE m_id = \"%s\""""%(request.args.get('id'))
        curs.execute(sql)


        if curs.rowcount == 0:
            conn.close()
            return "false"
        rows = curs.fetchall()
        if request.args.get('pass') != rows[0]['m_pass']:
            #print(json.dumps("false", ensure_ascii=False))
            #return json.dumps("false", ensure_ascii=False)
            conn.close()
            return "false"
        else:
            session['id']=rows[0]['m_id']
            session['name']=rows[0]['m_name']
            session['gender']=rows[0]['m_gender']
            session['mail']=rows[0]['m_mail']
            session['department']=rows[0]['m_department']
            session['nickname']=rows[0]['m_nickname']
            session['birth']=rows[0]['m_birth']
            session['phone']=rows[0]['m_phone']
            session['profile']=rows[0]['m_profile']
            session['job']=rows[0]['m_job']
            conn.close()
            return "true"



@app.route('/notice', methods = ['GET','POST'])
def get_notice():
    conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
    curs=conn.cursor(pymysql.cursors.DictCursor)
    if request.method == 'GET':

        sql = """SELECT * FROM notice_list where department = '한국장학재단' """
        curs.execute(sql)
        rows = curs.fetchall()

        data = []
        for i in range(len(rows)):
            js = OrderedDict()
            js["title"] = rows[i]['title']
            js["contents"] = rows[i]['contents']
            js["category"] = rows[i]['category']
            js["time"] = rows[i]['time']
            data.append(js)
        #print(data)
        obj = json.dumps(data, ensure_ascii = False)
        conn.close()
        return obj


@app.route('/community',methods = ['GET','POST'])
def community():
    # 커뮤니티 읽어오기
    if request.method == 'GET':
        #community_num = int(float(str(request.form.get('comunity_num'))))
        #params = json.loads(request.get_data(), encoding='utf-8')
        #community_num = request.form("community_num")
        community_num = request.args.get('community_num')
        sql = """SELECT * FROM bd_board where bc_code = \"%s\" """ %(community_num)

        # --
        conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
        curs=conn.cursor(pymysql.cursors.DictCursor)
        # --
        curs.execute(sql)
        rows = curs.fetchall()
        data = []
        for i in range(len(rows)):
            js = OrderedDict()
            js["writer"] = rows[i]["m_name"]
            js["title"] = rows[i]["b_title"]
            js["contents"] = rows[i]["b_contents"]
            js["time"] = rows[i]["b_regdate"]  #2021-12-30 07:20:50
            js["index"] = rows[i]["b_idx"]
            data.append(js)
        obj = json.dumps(data, ensure_ascii = False)
        conn.close()
        return obj

    if request.method == 'POST':
        conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
        curs=conn.cursor(pymysql.cursors.DictCursor)


        idx = board_last_idx()+1
        print("idx",idx)

        contents = request.args.get('contents')
        title = request.args.get('title')
        code = request.args.get('code',type=int)
        regdate = datetime.strptime(request.args.get('time'), '%Y-%m-%d %H:%M:%S')

        name = session['nickname']
        m_id = session['id']
        cnt = 0
        #regdate = datetime.now()



        sql = """insert into bd_board(b_idx,bc_code,m_id,m_name,b_title,b_contents,b_cnt,b_regdate)
                values(
                '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s'
                )
        """%(idx,code,m_id,name,title,contents,cnt,regdate)

        curs.execute(sql)
        conn.commit()
        conn.close()
        return 'ok'

@app.route('/comment', methods = ['GET','POST'])
def comment():
    if request.method == 'GET':
        parent_num = request.args.get('parent_num')

        conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
        curs=conn.cursor(pymysql.cursors.DictCursor)

        sql = """select * from bd_comment where b_idx = '%s' """%(parent_num)

        curs.execute(sql)
        rows = curs.fetchall()

        data = []

        for i in range(len(rows)):
            js = OrderedDict()
            #js["id"] = rows[i]["m_id"]
            js["name"] = rows[i]["m_name"]
            js["contents"] = rows[i]["co_contents"]
            js["regdate"] = rows[i]["co_regdate"].strftime('%Y-%m-%d : %H:%m')
            data.append(js)
        obj = json.dumps(data, ensure_ascii = False)
        conn.close()
        return obj



    if request.method == 'POST':
        conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
        curs=conn.cursor(pymysql.cursors.DictCursor)

        b_idx = request.args.get('parent_num',type=int)
        contents = request.args.get('contents')

        co_idx = comment_last_idx()+1
        m_id = session['id']
        name = session['nickname']
        regdate = datetime.strptime(request.args.get('time'), '%Y-%m-%d %H:%M:%S')

        sql = """insert into bd_comment(co_idx,b_idx,m_id,m_name,co_contents,co_regdate)
            values(
            '%s','%d','%s','%s','%s','%s'
            )
        """%(co_idx,b_idx,m_id,name,contents,regdate)

        curs.execute(sql)
        conn.commit()
        conn.close()

        return 'ok'






@app.route('/user', methods = ['GET'])
def get_userlist():
    conn = pymysql.connect(host=host, port=3306, user=id, password=pw, db=db_name, charset='utf8')
    curs=conn.cursor(pymysql.cursors.DictCursor)
    #print(request.args.get('department'))
    #sql = """SELECT * FROM bd_member where m_department = %s""" %(request.form.get('department'))
    sql = """SELECT * FROM bd_member where m_department = \"%s\"""" %(session['department'])
    curs.execute(sql)
    rows = curs.fetchall()


    data = []
    for i in range(len(rows)):
        js = OrderedDict()
        js["name"] = rows[i]['m_name']
        js["job"] = rows[i]['m_job']
        js["mail"] = rows[i]['m_mail']
        js['profile'] = rows[i]['m_profile']
        data.append(js)
    obj = json.dumps(data, ensure_ascii = False)
    conn.close()
    return obj

@app.route('/logout')
def logout():
    session.clear()
    return "OK"








if __name__ == '__main__':
    app.run(host="0.0.0.0", port=2222,debug=True)
