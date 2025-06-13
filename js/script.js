fetch("/data.csv")
  .then(response => response.text())
  .then(text => {
    const rows = text.trim().split("\n").slice(1);
    const ul = document.getElementById("product-list");

    rows.forEach(row => {
      const [name, price] = row.split(",");
      const li = document.createElement("li");
      li.textContent = `${name} - ${price}원`;
      ul.appendChild(li);
    });
  });
