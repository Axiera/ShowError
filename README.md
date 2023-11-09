## Описание
Функция для WinAPI. Получает код последней ошибки с помощью функции GetLastError. Отображает в диалоговом окне описание этой ошибки, а так же имя файла и строку, где была вызвана функция ShowError.

## Сигнатура функции
```c
INT ShowError(HWND hWnd, LPCSTR lpszFile, UINT uiLine);
```

## Аргументы функции
`HWND hWnd`

Дескриптор окна, которое станет родительским для диалогового окна. Этот аргумент может иметь значение NULL.

`LPCSTR lpszFile`

Этот аргумент должен иметь значение \_\_FILE\_\_.

`UINT uiLine`

Этот аргумент должен иметь значение \_\_LINE\_\_.

## Возвращаемые значения

| Возвращемое значение | Описание                                                 |
| -------------------: | -------------------------------------------------------- |
| 0                    | Функция завершилась без ошибок                           |
| 1                    | Функция GetLastError вернула 0                           |
| 2                    | Не удалось получить описание ошибки                      |
| 3                    | Не удалось выделить память для внутреннего использования |
| 4                    | Не удалось отобразить диалоговое окно                    |

