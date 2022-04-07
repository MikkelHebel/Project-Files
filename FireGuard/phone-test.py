import os
from twilio.rest import Client


# Find your Account SID and Auth Token at twilio.com/console
# and set the environment variables. See http://twil.io/secure
client = Client('ACd43dda35d113528b41f348cbc3235ef4', '3ad17f3b9dbdae1d0a2c317081c0de69')

message = client.messages \
                .create(
                     body="Fire Detected!",
                     from_='+19062562866',
                     to='+4531365107'
                 )

print(message.sid)