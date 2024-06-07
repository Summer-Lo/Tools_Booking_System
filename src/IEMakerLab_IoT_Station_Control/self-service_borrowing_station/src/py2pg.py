import psycopg2
import pandas as pd
import client_config as hc
import time
import datetime
import pytz

def get_data():

    with hc.conn.cursor() as cur:

        print(cur.rowcount)
        
        ## SQL Query
        sql = "select * from locker ORDER BY id ASC"
        
        ## Excute sql
        cur.execute(sql)
        
        ## Get cloumn name
        name = [desc[0] for desc in cur.description]
        
        rows = pd.DataFrame(cur.fetchall(),columns=name)

    #print(rows)
    print(rows.to_string())
    cur.close()
    #hc.conn.close()
    return rows

def update_status_data(locker_id, borrower_id, status):
    with hc.conn.cursor() as cur:

        #print(cur.rowcount)
        hk_tz = pytz.timezone('Asia/Hong_Kong')
        ## SQL Query
        date_updated = datetime.datetime.now(hk_tz).date().strftime('%Y-%m-%d')
        #print(date_updated)
        time_updated = datetime.datetime.now(hk_tz).time().strftime('%H:%M:%S')
        #print(time_updated)
        sql = f"UPDATE locker SET borrower_id = %s, date_updated = %s, time_updated = %s, status = %s WHERE id = %s"
        #sql = "UPDATE locker SET borrower_id = %s WHERE id = %s"
        #print(sql)
        ## Excute sql
        cur.execute(sql,(borrower_id,date_updated,time_updated,status,locker_id))

        # commit the changes to the database
        hc.conn.commit()
        if (borrower_id != ""):
            print(f"Locker {locker_id} is borrowed by {borrower_id}")
        else:
            print(f"Locker {locker_id} is returned and free now")
        ## Get cloumn name
        #name = [desc[0] for desc in cur.description]
        
        #rows = pd.DataFrame(cur.fetchall(),columns=name)
    cur.close()

    #print(rows)
    #hc.conn.close()
    #return rows

