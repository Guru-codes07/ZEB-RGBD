# ZEB-RGBD

**ZEB-RGBD (Zebronics RGB Daemon)** is a small Linux daemon written in **C** that keeps my **Zebronics keyboard RGB** turned on under **Wayland**.

On my **Fedora 44 + Hyprland** setup, the keyboard's RGB lighting is controlled by the **Scroll Lock LED**. Whenever another key is pressed, the Linux kernel resets the Scroll Lock LED, causing the RGB lighting to turn off.

This daemon continuously restores the Scroll Lock LED state, allowing the RGB lighting to remain enabled after pressing **Scroll Lock**.

> This project was created specifically for my personal setup and keyboard.

---

## Features

- Keeps the keyboard RGB enabled after pressing **Scroll Lock**
- Lightweight daemon written in **C**
- Designed for **Fedora 44 + Hyprland (Wayland)**
- Runs automatically using a **systemd user service**

---

## Project Structure

```text
ZEB-RGBD/
├── src/
│   └── main.c
├── systemd/
│   └── zeb-rgbd.service
├── Makefile
├── README.md
└── LICENSE
```

---

## Requirements

- Fedora Linux
- GCC
- Make
- A keyboard whose RGB is controlled by the **Scroll Lock LED**

---

## Build

```bash
git clone https://github.com/<your-username>/ZEB-RGBD.git
cd ZEB-RGBD
make
```

---

## Running

Run the daemon manually:

```bash
sudo ./zeb-rgbd
```

Or run it automatically using the included **systemd** service.

---

## Why I Made This

I use **Fedora 44** with **Hyprland (Wayland)** on my laptop.

Unlike X11, Wayland does not support controlling keyboard LEDs using the `xset` utility. My Zebronics keyboard uses the **Scroll Lock LED** to control its RGB lighting, which the Linux kernel resets whenever another key is pressed.

This daemon solves that problem for my setup.

---

## License

This project is licensed under the **MIT License**.

See the [LICENSE](LICENSE) file for more information.
