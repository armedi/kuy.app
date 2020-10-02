<template>
  <Hero />
  <LinkInput />
</template>

<script lang="ts">
import { defineComponent } from "vue";
import "./global.css";
import Hero from "./components/Hero.vue";
import LinkInput from "./components/LinkInput.vue";

export default defineComponent({
  name: "App",
  components: {
    Hero,
    LinkInput
  }
});
</script>
