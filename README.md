# ワサビ

## 書き込む前にすること

### WiFiの設定
```c
// WiFiConfig.h
const char *ssid = "";
const char *password = "";
```
というファイルを作る

### Armbientの設定
```c
// ArmbientConfig.h
unsigned int channelId = 0;
const char *writeKey = "";
```

## GPIO
|GPIO|接続先|
|-|-|
|22|温度センサ|
|5|FAN|
|21|RY1|
|10|RY2|
