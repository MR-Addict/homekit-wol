bool isValidMacAddress(const char* mac) {
  if (strlen(mac) != 17) return false;

  // 检查有效的十六进制字符和冒号
  for (int i = 0; i < 17; i++) {
    if (i % 3 == 2) {
      if (mac[i] != ':') return false;           // 每第三位应该是冒号
    } else if (!isxdigit(mac[i])) return false;  // 每个字符都应该是一个十六进制字符
  }

  return true;
}

void setMacCommand(const char* buf) {
  char mac[18];
  strncpy(mac, buf + 2, sizeof(mac) - 1);  // 复制CLI得到的MAC地址，命令和MAC之间有一个空格
  mac[sizeof(mac) - 1] = '\0';             // 添加一个结束符号

  if (!isValidMacAddress(mac)) Serial.println("Invalid MAC Address format. Please use XX:XX:XX:XX:XX:XX");
  else {
    preferences.putString("mac", mac);
    Serial.print("New MAC: ");
    Serial.println(mac);
  }
}
