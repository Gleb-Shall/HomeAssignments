# UML Диаграмма игрового процесса

## Диаграмма последовательности игрового процесса

```mermaid
sequenceDiagram
    participant U as User
    participant G as Game
    participant P as Player
    participant W as World
    participant B as Battle
    participant E as Enemy
    participant N as NPC
    participant S as Shop

    Note over U,S: Инициализация игры
    U->>G: Запуск игры
    G->>G: Init()
    G->>P: Создание игрока
    G->>W: Generate() - создание мира
    G->>W: SpawnEnemy() - появление врагов
    G->>N: Размещение NPC

    Note over U,S: Основной игровой цикл
    loop Игровой цикл
        G->>G: Render() - отрисовка
        G->>U: Показать интерфейс
        U->>G: Ввод команды
        
        alt Команда "move"
            G->>W: MovePlayer(dx, dy)
            W->>W: Проверка границ и препятствий
            W-->>G: Результат движения
            G->>W: MoveExtraEnemies() - движение врагов
            
            alt Враг рядом с игроком
                W->>G: IsNearEnemy() = true
                G->>B: Start(Player, Enemy, World)
                B->>B: active = true
                Note over U,S: Боевая система
                loop Бой
                    B->>B: PlayerTurn()
                    B->>P: Показать варианты действий
                    U->>B: Выбор действия
                    
                    alt Атака
                        B->>P: Attack(Enemy)
                        P->>E: TakeDamage(damage)
                        E-->>P: Результат атаки
                    else Защита
                        B->>P: Defend()
                        P->>P: defending = true
                    else Использование предмета
                        B->>P: UseItem(item)
                        P->>P: Применение эффекта
                    end
                    
                    alt Враг жив
                        B->>B: EnemyTurn()
                        B->>E: Think(Player)
                        E->>P: Attack(Player)
                        P->>P: TakeDamage(damage)
                    end
                    
                    B->>B: CheckWin()
                end
                
                alt Игрок победил
                    B->>E: DropLoot()
                    E->>P: Добавить предметы/золото
                    B->>B: End()
                    B->>W: ClearMainEnemy()
                else Игрок проиграл
                    B->>B: End()
                    G->>G: Game Over
                end
            end
        end
        
        alt Команда "talk" (рядом с NPC)
            G->>W: IsNearNPC()
            W-->>G: true
            G->>N: Talk()
            N->>U: Показать диалог
            
            alt NPC дает квест
                N->>G: GiveQuest()
                G->>G: questActive = true
            end
        end
        
        alt Команда "shop" (рядом с торговцем)
            G->>W: IsNearMerchant()
            W-->>G: true
            G->>S: ListGoods()
            S->>U: Показать товары
            U->>G: Выбор товара
            G->>S: Buy(Player, Item)
            S->>P: Списывание золота
            S->>P: Добавление предмета
        end
        
        alt Команда "inventory"
            G->>P: GetInventory()
            P->>U: Показать предметы
            U->>G: Выбор предмета
            G->>P: UseItem(item)
            P->>P: Применение эффекта
        end
        
        alt Команда "help"
            G->>G: PrintHelp()
            G->>U: Показать справку
        end
        
        alt Команда "quit"
            G->>G: Exit()
            break
        end
        
        G->>G: Update() - обновление состояния
    end
```

## Диаграмма состояний игрока

```mermaid
stateDiagram-v2
    [*] --> Idle: Игра начата
    
    Idle --> Moving: Команда "move"
    Idle --> Talking: Команда "talk" (рядом с NPC)
    Idle --> Shopping: Команда "shop" (рядом с торговцем)
    Idle --> UsingItem: Команда "inventory" + выбор предмета
    Idle --> [*]: Команда "quit"
    
    Moving --> Idle: Движение завершено
    Moving --> InBattle: Враг рядом
    
    InBattle --> Attacking: Атака
    InBattle --> Defending: Защита
    InBattle --> UsingItem: Использование предмета
    InBattle --> Idle: Бой завершен (победа/поражение)
    
    Attacking --> InBattle: Атака завершена
    Defending --> InBattle: Защита завершена
    UsingItem --> InBattle: Предмет использован
    
    Talking --> Idle: Диалог завершен
    Shopping --> Idle: Торговля завершена
    
    UsingItem --> Idle: Предмет использован (вне боя)
```

## Диаграмма состояний врага

```mermaid
stateDiagram-v2
    [*] --> Spawned: Враг создан
    
    Spawned --> Patrolling: Начало патрулирования
    Patrolling --> Moving: Случайное движение
    Patrolling --> Chasing: Игрок обнаружен
    Patrolling --> Spawned: Враг удален
    
    Moving --> Patrolling: Движение завершено
    Chasing --> InBattle: Игрок рядом
    Chasing --> Patrolling: Игрок потерян
    
    InBattle --> Attacking: Атака
    InBattle --> Defending: Защита
    InBattle --> Thinking: Выбор действия
    
    Attacking --> InBattle: Атака завершена
    Defending --> InBattle: Защита завершена
    Thinking --> InBattle: Действие выбрано
    
    InBattle --> Defeated: HP = 0
    Defeated --> [*]: Враг удален
```

## Диаграмма состояний предметов

```mermaid
stateDiagram-v2
    [*] --> Created: Предмет создан
    
    Created --> InInventory: Добавлен в инвентарь
    Created --> InShop: Добавлен в магазин
    Created --> Dropped: Выброшен на землю
    
    InInventory --> Equipped: Экипирован
    InInventory --> Used: Использован
    InInventory --> Sold: Продан
    
    InShop --> InInventory: Куплен игроком
    InShop --> Removed: Удален из магазина
    
    Equipped --> InInventory: Снят
    Equipped --> Broken: Сломано (оружие/броня)
    Equipped --> Used: Использован (зелье)
    
    Used --> Consumed: Потреблено (зелье)
    Used --> InInventory: Возвращено в инвентарь
    
    Broken --> Repaired: Отремонтировано
    Broken --> Discarded: Выброшено
    
    Consumed --> [*]: Удалено
    Discarded --> [*]: Удалено
    Removed --> [*]: Удалено
```

## Описание игрового процесса

### Основные состояния игры:
1. **Инициализация** - создание всех объектов, генерация мира
2. **Игровой цикл** - основной цикл обработки команд
3. **Бой** - пошаговая боевая система
4. **Взаимодействие** - диалоги с NPC, торговля
5. **Завершение** - выход из игры

### Ключевые механики:
- **Движение** - перемещение по карте с проверкой препятствий
- **Бой** - пошаговая система с выбором действий
- **Инвентарь** - управление предметами и их использование
- **Квесты** - получение и выполнение заданий
- **Торговля** - покупка и продажа предметов
- **Улучшения** - апгрейд оружия и брони
