<template>
  <Hero />
  <LinkInput
    v-if="state.show === 'input'"
    :loading="state.loading"
    @submit-link="handleSubmit"
  />
  <LinkResult
    v-else-if="state.show === 'result'"
    :result="state.result"
    :error="state.error"
    @reset="handleReset"
  />
</template>

<script lang="ts">
import { defineComponent, provide, toRef } from "vue";

import "@/global.css";
import { useState } from "./data";
import Hero from "@/components/Hero.vue";
import LinkInput from "@/components/LinkInput.vue";
import LinkResult from "@/components/LinkResult.vue";

export default defineComponent({
  name: "App",
  components: {
    Hero,
    LinkInput,
    LinkResult
  },
  setup() {
    const [state, { submitLink, reset }] = useState();

    return {
      state,
      handleSubmit: submitLink,
      handleReset: reset
    };
  }
});
</script>
