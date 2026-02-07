library(dplyr)
library(skimr)
library(Hmisc)

df <- data.frame(
  idade = c(25, 30, 35, 40, 28, 33, 29, 45, 38, 32),
  sexo = c("M", "F", "M", "F", "M", "F", "M", "F", "M", "F"),
  salario = c(3000, 3500, 4000, 4500, 3200, 3800, 3100, 5000, 4200, 3600)
)


skimr::skim(df)
Hmisc::describe(df)


hist(df$salario,
     main = "Histograma da Variável",
     xlab = "Valores",
     ylab = "Frequência",
     col = "lightblue",
     border = "black")

library(ggplot2)
ggplot(df, aes(x = salario)) +
  geom_histogram(bins = 4, fill = "steelblue", color = "black") +
  labs(title = "Histograma da Variável",
       x = "Valores",
       y = "Frequência") +
  theme_minimal()

boxplot(df$salario,
        main = "Box-plot da Variável",
        ylab = "Valores",
        col = "white")

# Box-plot por grupos
boxplot(salario ~ sexo,
        data = df,
        main = "Box-plot por Categoria",
        xlab = "Categoria",
        ylab = "Valores",
        col = c("lightblue", "lightgreen", "pink"))
# Com ggplot2
library(ggplot2)
ggplot(df, aes(y = variavel_quantitativa)) +
  geom_boxplot(fill = "steelblue") +
  labs(title = "Box-plot da Variável",
       y = "Valores") +
  theme_minimal()

# Box-plot por grupos com ggplot2
ggplot(df, aes(x = sexo, y = salario, fill = sexo)) +
  geom_boxplot() +
  labs(title = "Box-plot por Categoria",
       x = "Categoria",
       y = "Valores") +
  theme_minimal()