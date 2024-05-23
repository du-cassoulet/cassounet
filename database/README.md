# CDB (Cassou DataBase)

CDB is a database language that is used to store and retrieve data in a CassouNet application.

```cdb
table animals {
  id=INT[default=auto_incr]
  name=STRING[maxsize=50,default=""]
}

table users {
  id=INT[default=auto_incr]
  age=INT[min=0,max=130,required=true],
  name=STRING[maxsize=50,default=""]
  pets=LIST[references=animals]
}

get users[sort_by=age] {
  id=[between=1,10]
}

add_to users {
  age=20,
  name="John"
}
```
