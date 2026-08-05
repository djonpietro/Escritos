#%%
function quantile(x, p)
    # cria estatísticas de ordem
    s = sort(x)
    # obtém o tamanho de vetor
    n = length(s)
    # caso de borda: se há um única estatística, retorna-a
    n = 1 && return s[1]
    # vetor de probabilidade acumulada por estatística
    probs = zeros(n)
    for i in 1:n
        probs[i] = (i - 1) / (n - 1)
    end
    # casos de borda
    if p <= probs[1]
        return s[1]
    elseif p >= probs[n]
        return s[n]
    end
    # busca binária pela posição de p em probs
    i = searchsortedfirst(probs, p)
    if probs[i] ≈ p
        return s[i]
    end
    # interpolação linear para encontrar o quantil empírico
    λ = (p - probs[i-1]) / (probs[i] - probs[i-1])
    q = (1-λ) * s[i-1] + λ * s[i]
    return q
end

function quantile_seven(x, p)
    s = sort(x)
    n = length(s)

    n == 1 && return s[1]

    h = (n-1)*p + 1
    j = floor(Int, h)
    if j == n
        return n
    end

    γ = h - j
    return (1 - γ) * s[j] + γ * s[j+1]
end

x = [2, 4, 6, 10, 8]
quantile_seven(x, 0.5)