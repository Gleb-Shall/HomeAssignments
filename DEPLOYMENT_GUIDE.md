# Руководство по развертыванию документации

## Быстрый старт

### 1. Настройка GitHub Pages
```bash
# 1. Перейдите в настройки репозитория на GitHub
# 2. Pages → Source → GitHub Actions
# 3. Actions → General → Workflow permissions → Read and write permissions
```

### 2. Развертывание
```bash
# Сделайте commit и push изменений
git add .
git commit -m "Add GitHub Pages deployment"
git push origin main
```

### 3. Проверка
- Документация будет доступна по адресу: `https://glebsikunov.github.io/HomeAssignments/`
- Проверьте статус в разделе Actions на GitHub

## Что было настроено

✅ **GitHub Actions workflow** (`.github/workflows/deploy-docs.yml`)
- Автоматическая генерация документации с помощью Doxygen
- Развертывание на GitHub Pages при push в main

✅ **Главная страница** (`index.html`)
- Красивый интерфейс с ссылкой на документацию
- Адаптивный дизайн

✅ **Конфигурация** (`.nojekyll`)
- Корректная работа с файлами, начинающимися с подчеркивания

✅ **Документация** (`lab2/docs/html/`)
- Автоматически генерируемая документация Doxygen
- Доступна по адресу `/docs/`

## Структура URL

- Главная страница: `https://glebsikunov.github.io/HomeAssignments/`
- Документация: `https://glebsikunov.github.io/HomeAssignments/docs/`

## Автоматическое обновление

Документация обновляется автоматически при каждом push в ветку main. Workflow:
1. Устанавливает Doxygen
2. Генерирует документацию из `lab2/` 
3. Развертывает в папку `docs/` на GitHub Pages
