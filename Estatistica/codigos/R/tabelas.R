library(Hmisc)
library(ggplot2)
library(dplyr)
load(url(description = "https://www.ime.usp.br/~pam/dados.RData"))

hist(cd_notas, col="darkblue", xlab ="Notas", ylab="Frequência", border="white" )
Hmisc::describe(tab2_1)

stripchart(cd_notas, method = "stack", offset = 2, at = 0, pch = 19, cex = 0.5)

stem(cd_notas$nota)

hist(cd_poluicao$temp, xlab = "temperatura", ylab= "frequência", border = "white", col = "darkblue")

stripchart(cd_poluicao$temp, xlab = "Temperatura", ylab = NA, method = "stack", offset  = 2,
at = 0, pch = 19, cex = 0.5, col = "darkblue")

stem(cd_poluicao$temp, scale = .5)

cd_brasil |>
  group_by(regiao) |>
  summarise(
    count = n()
  ) |>
  ggplot(aes(x = regiao, y = count)) +
    geom_col()
