// Falling flowers effect
const flowers = ["🌸", "🌼", "🌺", "🌹"];
function createFlower() {
  const flower = document.createElement("div");
  flower.classList.add("flower");
  flower.innerText = flowers[Math.floor(Math.random() * flowers.length)];
  flower.style.left = Math.random() * 100 + "vw";
  flower.style.animationDuration = (4 + Math.random() * 4) + "s";
  document.body.appendChild(flower);
  setTimeout(() => flower.remove(), 8000);
}
setInterval(createFlower, 800);

// Header glow pulsing
const header = document.querySelector("header");
setInterval(() => {
  header.style.textShadow =
    "0 0 10px gold, 0 0 20px orange, 0 0 30px red";
  setTimeout(() => {
    header.style.textShadow =
      "2px 2px 6px rgba(0,0,0,0.5), 0 0 15px gold";
  }, 500);
}, 2000);

// Smooth scroll on divider click
document.querySelectorAll(".divider").forEach(div => {
  div.addEventListener("click", () => {
    window.scrollBy({ top: window.innerHeight / 2, behavior: "smooth" });
  });
});
