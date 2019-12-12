from __future__ import print_function
from datetime import datetime

import json
import boto3
import os

print('Loading function')

s3 = boto3.client('s3')

def lambda_handler(event, context):
    bucket = os.getenv("S3_BUCKET")

    key = formatKey()
    body = event['body']
    try:
        response = s3.put_object(Bucket=bucket, Key=key, Body=body)
        return response
    except Exception as e:
        print(e)
        print('Error putting object {} into bucket {}.'.format(key, bucket))
        raise e
        
def formatKey():
    now = datetime.now()
    key = now.strftime("%Y/%m/%d/%H/") + "data.json"
    return key
